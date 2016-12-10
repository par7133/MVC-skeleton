<?php

class Bootstrap
{

  protected $controller = "HomeController";
  
  protected $action = "index";
  
  protected $qs = [];
  
  //protected $params = [];
  
  public function __construct()
  {
    settype($url, "array");
    settype($qs, "string");
    
    $this->parseGET($url, $qs);
    
    if (file_exists("../Private/controllers/" . $url[0] . "controller.inc")) {
      $this->controller = ucfirst($url[0]) . "Controller";
      unset($url[0]);
    }
    
    $this->controller = new $this->controller;
    
    if (isset($url[1])) {
      if (method_exists($this->controller, $url[1])) {
        $this->action = $url[1];
        unset($url[1]);
      }
    }
    
    //$this->params = $url ? array_values($url) : [];
    
    $this->qs = $qs;
    
    //call_user_func_array([$this->controller, $this->action], $this->params);
    
    call_user_func_array([$this->controller, $this->action], [$this->qs]);
  }
  
  public function parseGET(& $url, & $qs)
  {
    if (isset($_GET['url'])) {
      $url = explode("/", strtolower(filter_var(rtrim($_GET['url'], "/"), FILTER_SANITIZE_STRING)));
    }
    
    if (count($_GET) > 1) {
      foreach ($_GET as $key => $value) {
        if ($key!="url") {
          $qs .= $key . "=" . $value . "&";
        }
      }
      $qs = rtrim($qs, "&");
    }
  }
  
}

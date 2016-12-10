<?php

/**
 * Copyright (c) 2016, the MVC-skeleton's contributors
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither MVC-skeleton nor the names of its contributors 
 *       may be used to endorse or promote products derived from this software 
 *       without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * bootstrap.inc
 * 
 * Bootstrap class.
 *
 * @author Daniele Bonini <danielemi@hotmail.com>
 * @copyrights (c) 2016, the MVC-skeleton's contributors     
 * @license https://opensource.org/licenses/BSD-3-Clause 
 */

/**
 * Bootstrap
 *
 * Bootstrap class
 *
 * @package  bootstrap
 * @author   Daniele Bonini <danielemi@hotmail.com>
 * @version  1.0
 * @access   public
 */
class Bootstrap
{
  /**
   * The controller
   *  
   * @access protected
   */
  protected $controller = "HomeController";
  
  /**
   * The action
   *  
   * @access protected
   */
  protected $action = "index";

  /**
   * The query string
   *  
   * @access protected
   */
  protected $qs = [];
  
  /**
   * The parameters
   * 
   * @access protected
   */
  //protected $params = [];
  
  /**
   * Default constructor
   */
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
  
  /**
   * Parse the $_GET array
   * 
   * @param array $url  the url
   * @param string $qs   the query string
   */
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


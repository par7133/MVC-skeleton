<?php

class Controller 
{

  public function model($model) 
  {
    return new $model();
  }
  
  public function view($view, $aModels = [])
  {
    require "../Private/views/" . $view . ".php";
  }
}

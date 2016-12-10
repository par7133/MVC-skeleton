<?php

class HomeController extends Controller
{
  public function index($qs) {
    
    settype($aModels, "array");
    
    $_GET1 = arrayFromQS($qs);
    
    $modelUser = $this->model("User");
    $modelUser->firstname = $_GET1['fn'];
    $modelUser->surname = $_GET1['sn'];
    
    $aModels["User"] = $modelUser; 
    
    $this->view('home/index', $aModels);
  } 
}

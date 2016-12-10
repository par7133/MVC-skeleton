<?php

  function arrayFromQS ($qs) {
    
    settype($retval, "array");
    settype($aPairs, "array");
    
    $aPairs = explode("&", rtrim($qs, "&"));
    
    foreach ($aPairs as $pair) {
      $aPair = explode("=", $pair);
      
      $retval[$aPair[0]] = $aPair[1];
    }
    
    return $retval;
  }


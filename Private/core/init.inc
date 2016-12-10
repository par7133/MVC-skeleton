<?php

// AUTOLOADER

define("CORE_PATH", __DIR__ . DIRECTORY_SEPARATOR . ".." . DIRECTORY_SEPARATOR . "core");

define("CLASSES_PATH", __DIR__ . DIRECTORY_SEPARATOR . ".." . DIRECTORY_SEPARATOR . "classes");
define("CONTROLLERS_PATH", __DIR__ . DIRECTORY_SEPARATOR . ".." . DIRECTORY_SEPARATOR . "controllers");
define("INTERFACES_PATH", __DIR__ . DIRECTORY_SEPARATOR . ".." . DIRECTORY_SEPARATOR . "interfaces");

/**
 * Autoloader.
 * 
 * @param string $construct the name of the construct to load
 */
function autoloader($construct) {
  
  $constructParts = explode('\\', $construct);
  
  // estrapolate the path from the construct name
  $count = count($constructParts);
  if ($count>1) {
    $i = 0;
    $constructPath = $constructParts[0];
    for ($i=1; $i<($count-1); $i++) {
      $constructPath .= DIRECTORY_SEPARATOR . $constructParts[$i];
    }
    $construct = $constructParts[$i];
  }
  
  //echo "including.. " . $construct . "<br>" . PHP_EOL;
  
  if (stripos($construct, "interface")) {
    // if it is an interface
    if (isset($constructPath)) {
      $incPath = INTERFACES_PATH . DIRECTORY_SEPARATOR  . $constructPath . DIRECTORY_SEPARATOR . strtolower($construct) . ".inc";
    } else {
      $incPath = INTERFACES_PATH . DIRECTORY_SEPARATOR . strtolower($construct) . ".inc";
    }  
    
  } elseif (stripos($construct, "controller")) {
    // if it is an controller
    if (isset($constructPath)) {
      $incPath = CONTROLLERS_PATH . DIRECTORY_SEPARATOR  . $constructPath . DIRECTORY_SEPARATOR . strtolower($construct) . ".inc";
    } else {
      $incPath = CONTROLLERS_PATH . DIRECTORY_SEPARATOR . strtolower($construct) . ".inc";
    }  
  
  } elseif ($construct === "Bootstrap") {
    // if it is the bootstrap  

    $incPath = CORE_PATH . DIRECTORY_SEPARATOR . "bootstrap.inc";
    
  } else {
    // if it is a class
    if (isset($constructPath)) {
      $incPath = CLASSES_PATH . DIRECTORY_SEPARATOR . $constructPath . DIRECTORY_SEPARATOR . "class." . strtolower($construct) . ".inc";
    } else {
      $incPath = CLASSES_PATH . DIRECTORY_SEPARATOR . "class." . strtolower($construct) . ".inc";
    }

  }
  
  if (is_readable($incPath)) {
    require $incPath;
  }
  
}
spl_autoload_register("autoloader", true, true);
  

// FUNCTIONS

define("FUNCTIONS_PATH", __DIR__.DIRECTORY_SEPARATOR."..".DIRECTORY_SEPARATOR."functions");

require FUNCTIONS_PATH . DIRECTORY_SEPARATOR . "func.various.inc";


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
 * init.inc
 * 
 * Initialization script.
 *
 * @author Daniele Bonini <danielemi@hotmail.com>
 * @copyrights (c) 2016, the MVC-skeleton's contributors     
 * @license https://opensource.org/licenses/BSD-3-Clause 
 */

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


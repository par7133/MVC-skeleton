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
 * func.various.inc
 * 
 * Various functions.
 *
 * @author Daniele Bonini <danielemi@hotmail.com>
 * @copyrights (c) 2016, the MVC-skeleton's contributors     
 * @license https://opensource.org/licenses/BSD-3-Clause 
 */

/**
 * Convert a query string in array format
 * 
 * @param string $qs the query string
 * @return array the converted array
 */
function arrayFromQS ($qs) {

  settype($retval, "array");
  settype($aPairs, "array");

  if ($qs==="") {
    return [];
  }
    
  $aPairs = explode("&", rtrim($qs, "&"));

  foreach ($aPairs as $pair) {
    $aPair = explode("=", $pair);

    $retval[$aPair[0]] = $aPair[1];
  }

  return $retval;
}

/**
 * Check if a variable is set with a default return
 * 
 * @param mixed $var the variable to check
 * @param mixed $default the default value
 * @return mixed the return value
 */
function isset1(& $var, $default) {
  if (isset($var)) {
    return $var;
  } else {
    return $default;
  }
}
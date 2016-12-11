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
 * homecontroller.inc
 * 
 * Home controller.
 *
 * @author Daniele Bonini <danielemi@hotmail.com>
 * @copyrights (c) 2016, the MVC-skeleton's contributors     
 * @license https://opensource.org/licenses/BSD-3-Clause 
 */

/**
 * HomeController
 *
 * HomeController class
 *
 * @package  controllers
 * @author   Daniele Bonini <danielemi@hotmail.com>
 * @version  1.0
 * @access   public
 */
class HomeController extends Controller
{
  /**
   * The index action
   * 
   * @param string $qs the query string
   */
  public function index($qs) 
  {
    settype($aModels, "array");
    
    $_GET1 = arrayFromQS($qs);
    
    $modelUser = $this->model("User");
    $modelUser->firstname = isset1($_GET1['fn'], "donald");
    $modelUser->surname = isset1($_GET1['sn'], "duck");
    
    $aModels["User"] = $modelUser; 
    
    $this->view('home/index', $aModels);
  } 
}

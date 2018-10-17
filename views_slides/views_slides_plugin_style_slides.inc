<?php
/**
* Implementation of views_plugin_style
*
*/
class views_slides_plugin_style_slides extends views_plugin_style {

  // just set default options on this object 
  function options(&$options) {
    $options['preload'] = FALSE;	// Set true to preload images in an image based slideshow
    $options['preloadImage'] = 'img/loading.gif';	// Name and location of loading image for (default) preloader
    $options['container'] = 'slides_container';	// Class name for slides container
    $options['generateNextPrev'] = FALSE;	// Auto generate next/prev buttons
    $options['next'] = 'next';	// Class name for next button
    $options['prev'] = 'prev';	// Class name for prev button
    $options['pagination'] = TRUE;	// If you're not using pagination you can set to false, but don't have to
    $options['generatePagination'] = TRUE;	// Auto generate pagination
    $options['prependPagination'] = FALSE;	// Prepend pagination
    $options['paginationClass'] = 'pagination';	// Class name for paginationClass
    $options['currentClass'] = 'current';	// Class name for current pagination item
    $options['fadeSpeed'] = 350;	// Set the speed of the fading animation in milliseconds
    $options['fadeEasing'] = '';	// Set the easing of the fade animation, Must include Easing plugin in your project
    $options['slideSpeed'] = 350;	// Set the speed of the sliding animation in milliseconds
    $options['slideEasing'] = '';	// Set the easing of the sliding animation. Must include Easing plugin in your project
    $options['start'] = 1;	// Set which slide you'd like to start with. Default is 1 and will start on the first slide
    $options['effect'] = array('slide' => t('Slide')); // Set effect, slide or fade for next/prev and pagination. If you use just one effect name it'll be applied to both or you can state two effect names. The first name will be for next/prev and the second will be for pagination. Must be separated by a comma.
    $options['crossfade'] = FALSE;	// Crossfade images in a image based slideshow
    $options['randomize'] = FALSE;	// Set to true to randomize slides
    $options['play'] = 0;	// Autoplay slideshow, a positive number will set to true and be the time between slide animation in milliseconds
    $options['pause'] = 0;	// Pause slideshow on click of next/prev or pagination. A positive number will set to true and be the time of pause in milliseconds
    $options['hoverPause'] = FALSE;	// Set to true and hovering over slideshow will pause it
    $options['autoHeight'] = FALSE;	// Set to true to auto adjust height
    $options['autoHeightSpeed'] = 350;	// Set auto height animation time in milliseconds
    $options['bigTarget'] = FALSE;	// Set to true and the whole slide will link to next slide on click
    $options['animationStart'] = '';	// Function called at the start of animation
    $options['animationComplete'] = '';	// Function called at the completion of animation
    $options['slidesLoaded'] = '';	// Function is called when slides is fully loaded
  }
  
  // Provide a form to edit options for this plugin. 
  function options_form(&$form, &$form_state) {
    $options = $this->display->handler->get_field_labels();
    $form['preload'] = array(
      '#type' => 'checkbox',
      '#title' => t('Set to preload images in an image based slideshow'),
      '#default_value' => $this->options['preload'],
    );
    $form['preloadImage'] = array(
      '#type' => 'textfield',
      '#size' => 10,
      '#title' => t('Preload Image'),
      '#description' => t('Name and location of loading image for (default) preloader. Path relative to module folder'),
      '#default_value' => $this->options['preloadImage'],
    );
    $form['container'] = array(
      '#type' => 'textfield',
      '#size' => 20,
      '#title' => t('CSS container class'),
      '#description' => t('Class name for slides container'),
      '#default_value' => $this->options['container'],
    );
    $form['generateNextPrev'] = array(
      '#type' => 'checkbox',
      '#title' => t('Auto generate next/prev buttons'),
      '#default_value' => $this->options['generateNextPrev'],
    );
    $form['next'] = array(
      '#type' => 'textfield',
      '#size' => 10,
      '#title' => t('CSS next button'),
      '#description' => t('Class name for next button'),
      '#default_value' => $this->options['next'],
    );
    $form['prev'] = array(
      '#type' => 'textfield',
      '#size' => 10,
      '#title' => t('CSS prev button'),
      '#description' => t('Class name for prev button'),
      '#default_value' => $this->options['prev'],
    );
    $form['pagination'] = array(
      '#type' => 'checkbox',
      '#title' => t('If you\'re not using pagination you can set to false, but don\'t have to'),
      '#default_value' => $this->options['pagination'],
    );
    $form['generatePagination'] = array(
      '#type' => 'checkbox',
      '#title' => t('Auto generate pagination'),
      '#default_value' => $this->options['generatePagination'],
    );
    $form['prependPagination'] = array(
      '#type' => 'checkbox',
      '#title' => t('Prepend pagination'),
      '#default_value' => $this->options['prependPagination'],
    );
    $form['paginationClass'] = array(
      '#type' => 'textfield',
      '#size' => 10,
      '#title' => t('CSS pagination Class'),
      '#description' => t('Class name for paginationClass'),
      '#default_value' => $this->options['paginationClass'],
    );
    $form['currentClass'] = array(
      '#type' => 'textfield',
      '#size' => 10,
      '#title' => t('CSS pagination current item'),
      '#description' => t('Class name for current pagination item'),
      '#default_value' => $this->options['currentClass'],
    );
    $form['fadeSpeed'] = array(
      '#type' => 'textfield',
      '#size' => 10,
      '#title' => t('Fade speed'),
      '#description' => t('Set the speed of the fading animation in milliseconds'),
      '#default_value' => $this->options['fadeSpeed'],
    );
    $form['fadeEasing'] = array(
      '#type' => 'textfield',
      '#size' => 10,
      '#title' => t('Fade easing'),
      '#description' => t('Set the easing of the fade animation, Must include Easing plugin in your project, http://gsgd.co.uk/sandbox/jquery/easing/'),
      '#default_value' => $this->options['fadeEasing'],
    );
    $form['slideSpeed'] = array(
      '#type' => 'textfield',
      '#size' => 10,
      '#title' => t('Slide speed'),
      '#description' => t('Set the speed of the sliding animation in milliseconds'),
      '#default_value' => $this->options['slideSpeed'],
    );
    $form['slideEasing'] = array(
      '#type' => 'textfield',
      '#size' => 10,
      '#title' => t('Slide easing'),
      '#description' => t('Set the easing of the sliding animation. Must include Easing plugin in your project, http://gsgd.co.uk/sandbox/jquery/easing/'),
      '#default_value' => $this->options['slideEasing'],
    );
    $form['start'] = array(
      '#type' => 'textfield',
      '#size' => 10,
      '#title' => t('Start slide'),
      '#description' => t('Set which slide you\'d like to start with. Default is 1 and will start on the first slide'),
      '#default_value' => $this->options['start'],
    );
    $form['effect'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Slide effect'),
      '#description' => t('Set effect, slide or fade for next/prev and pagination. If you use just one effect name it\'ll be applied to both or you can state two effect names. The first name will be for next/prev and the second will be for pagination. None will default to slide.'),
      '#default_value' => $this->options['effect'],
      '#options' => array('slide' => t('Slide'), 'fade' => t('Fade')),
    );    
    $form['crossfade'] = array(
      '#type' => 'checkbox',
      '#title' => t('Crossfade images in a image based slideshow'),
      '#default_value' => $this->options['crossfade'],
    );
    $form['randomize'] = array(
      '#type' => 'checkbox',
      '#title' => t('Set to randomize slides'),
      '#default_value' => $this->options['randomize'],
    );
    $form['play'] = array(
      '#type' => 'textfield',
      '#size' => 10,
      '#title' => t('Autoplay slideshow'),
      '#description' => t('Autoplay slideshow, a positive number will set to true and be the time between slide animation in milliseconds'),
      '#default_value' => $this->options['play'],
    );
    $form['pause'] = array(
      '#type' => 'textfield',
      '#size' => 10,
      '#title' => t('Pause slideshow'),
      '#description' => t('Pause slideshow on click of next/prev or pagination. A positive number will set to true and be the time of pause in milliseconds'),
      '#default_value' => $this->options['pause'],
    );
    $form['hoverPause'] = array(
      '#type' => 'checkbox',
      '#title' => t('Set to true and hovering over slideshow will pause it'),
      '#default_value' => $this->options['hoverPause'],
    );
    $form['autoHeight'] = array(
      '#type' => 'checkbox',
      '#title' => t('Set to auto adjust height'),
      '#default_value' => $this->options['autoHeight'],
    );
    $form['autoHeightSpeed'] = array(
      '#type' => 'textfield',
      '#size' => 10,
      '#title' => t('Auto height speed'),
      '#description' => t('Set auto height animation time in milliseconds'),
      '#default_value' => $this->options['autoHeightSpeed'],
    );
    $form['bigTarget'] = array(
      '#type' => 'checkbox',
      '#title' => t('Set to true and the whole slide will link to next slide on click'),
      '#default_value' => $this->options['bigTarget'],
    );
    $form['animationStart'] = array(
      '#type' => 'checkbox',      
      '#title' => t('Animation start callback'),
      '#description' => t('Function called at the start of animation. Use file event_start.js with function called when the event occurs (click or mouseover)'),
      '#default_value' => $this->options['animationStart'],
    );
    $form['animationComplete'] = array(
      '#type' => 'checkbox',      
      '#title' => t('Animation completed callback'),
      '#description' => t('Function called at the completion of animation. Use file event_completed.js with function called when animation completes'),
      '#default_value' => $this->options['animationComplete'],
    );
    $form['slidesLoaded'] = array(
      '#type' => 'checkbox',      
      '#title' => t('Slides loaded callback'),
      '#description' => t('Function is called when slides is fully loaded. Use file event_slidesLoaded.js with function called when slides are loaded'),
      '#default_value' => $this->options['slidesLoaded'],
    );
  }

  /**
   * Validate the options form.
   */
  function options_validate(&$form, &$form_state) {
    parent::options_validate($form, $form_state);
    $options = &$form_state['values']['style_options'];    
    if ($options['preloadImage']) {
      $preload_image = drupal_get_path('module', 'views_slides') . '/' . $options['preloadImage'];      
      if(!file_exists($preload_image)) {        
	form_error($form['preloadImage'], t('Please specify valid path'));
      }
    }
    if (empty($options['container'])) {
      form_error($form['container'], t('Please specify a class name for slides container or leave default value: slides_container'));
    }
    if (empty($options['next'])) {
      form_error($form['next'], t('Please specify a class name for next button or leave default value: next'));
    }
    if (empty($options['prev'])) {
      form_error($form['prev'], t('Please specify a class name for prev button or leave default value: prev'));
    }
    if (empty($options['paginationClass'])) {
      form_error($form['paginationClass'], t('Please specify a class name for pagination or leave default value: pagination'));
    }
    if (empty($options['currentClass'])) {
      form_error($form['currentClass'], t('Please specify a class name for current pagination item or leave default value: current'));
    }
    if (!is_numeric($options['fadeSpeed'])) {
      form_error($form['fadeSpeed'], t('Please specify a numerical value for Fade speed'));
    }
    if (!is_numeric($options['slideSpeed'])) {
      form_error($form['slideSpeed'], t('Please specify a numerical value for Slide speed'));
    }
    if (!is_numeric($options['start'])) {
      form_error($form['start'], t('Please specify a numerical value for Start slide'));
    }
    if (!is_numeric($options['play'])) {
      form_error($form['play'], t('Please specify a numerical value for Autoplay slideshow'));
    }
    if (!is_numeric($options['pause'])) {
      form_error($form['pause'], t('Please specify a numerical value for Pause slideshow'));
    }
    if (!is_numeric($options['autoHeightSpeed'])) {
      form_error($form['autoHeightSpeed'], t('Please specify a numerical value for Auto height speed'));
    }
  }

  // Allow the style to do stuff before each row is rendered. 
  function pre_render($result) {
    if (!empty($this->row_plugin)) {
      $this->row_plugin->pre_render($result);
    }
  }


}



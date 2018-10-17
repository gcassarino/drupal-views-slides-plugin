<?php

/**
 * Implements hook_views_plugins().
 */
function views_slides_views_plugins() {
  return array(
    'style' => array(
      'slides' => array(
        'title' => t('Slides'),
        'help' => t('Display the results using Slides.'),
        'handler' => 'views_slides_plugin_style_slides',
        'theme' => 'views_slides',
        'uses options' => TRUE,
        'uses row plugin' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
}



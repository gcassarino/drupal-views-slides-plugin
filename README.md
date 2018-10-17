# drupal-views-slides-plugin
Drupal 6 Views Style plugin that displays results using the SlidesJS http://slidesjs.com/ plugin for JQuery.

[DEMO](http://www.quovadiscom.com/content/drupal-views-slides-plugin)

Slides uses a version of jQuery 1.4.4 above, in this case 1.6.2 is used. The method "jQuery.noConflict" is used to avoid breaking other scripts on the page. It should work. Drupal Ajax pager is supported.

This module provides a new Style option called "slides" when choosing the Display Style of the View.

The module should work as it is, the files slides.min.jquery.js and updated JQuery are located inside the "slides/js/" module's folder.

![slides-views settings](http://www.quovadiscom.com/sites/default/files/slides-views-sshot.jpg "slides-views settings") Access to plugin settings page to adjust the options. Options from Slides plugin are available.

SlidesJS plugin actually support 3 events: on start, stop and on load. Select the desired event (optionally) in the plugin Style settings and then modify the corresponding files inside the module's folder as you wish. The files are event_init.js, event_slidesLoaded.js, event_completed.js

# NOTE:
this is an old project for Drupal 6 reported here on Github for the convenience of [those who still use D6](https://www.drupal.org/project/usage/drupal), the original page is here http://www.quovadiscom.com/content/drupal-views-slides-plugin


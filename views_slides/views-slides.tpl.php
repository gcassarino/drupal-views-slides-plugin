<?php
// $Id: 

/**
 * @file views-slides.tpl.php
 * View template to display a list using Slides.
 */
?>
<div id="slides-<?php print $view->name; ?>">
  <div class="slides_container">
    <?php 
      $slide_id = 0; // zero based index for id
      foreach ($rows as $row) :      
    ?>
	<div id="slides-<?php print $slide_id; ?>-slide-<?php print $slide_id; ?>"><?php print $row; ?></div>
    <?php
      $slide_id++;
      endforeach; 
    ?>
  </div>
</div>
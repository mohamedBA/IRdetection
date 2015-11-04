# IRdetection
IRdetection is a simple application developed by c++ language and opencv library.
the principal role of this application is to detect defects in a thermal image by drawing contour and calculating its area.
this application let the user to import a thermal image which have many defects.then select with the mouse a part from this image which have 
which have one defect.when the user selects this part, he can create a region of interst(ROI) with the selected part.after that,
he can apply k-means algorithm to segment the ROI into two parts healthy and fault.in the end he can draw the contour of fault
part and calculte its area.

(defun matrix (n)

  (loop for i from 0 to (- n 1) do

  (setq size (expt 2 i))
  (setf a (make-array (list size size)))
  (setf c (make-array (list size size)))
  (loop for p from 0 to (- size 1) do
		(loop for q from 0 to (- size 1) do
			  (setf (aref a p q) 1)
			  (setf (aref c p q) 0)))

  (setq tstart (get-internal-real-time))

  (loop for p from 0 to (- size 1) do
		(loop for q from 0 to (- size 1) do
			  (loop for r from 0 to (- size 1) do
					(setf (aref c p q) (+ (aref c p q) (* (aref a p r) (aref a r q)))))))

  (setq tend  (get-internal-real-time))

  (print (float (- tend tstart)))
  ))


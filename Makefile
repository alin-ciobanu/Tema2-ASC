
draw-plot:
	sh draw.sh

view-plot:
	eog graph.png

submit-jobs:
	sh run.sh

clean:
	rm data.out
	rm graph.png

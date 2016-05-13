COpencvWrap
{
	init();

	addline(1, x1,y1, x2,y2, left | right);
	addline(2, x1,y1, x2,y2, right);
	addline(3, x3,y3, x4,y4, right);

	while(1) {
		bool putimage(imagebuffer, width, height, int  *line_id[]);		// opencvº∆À„
		if(result &&  liuxin_result) {
			compress(imagebuffer);
			net_send();
		}
		
		addline(5, x6,y6, x7,y7, bottom);
		delline(3);
	}
}
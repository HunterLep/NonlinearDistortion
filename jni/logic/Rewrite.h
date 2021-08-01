#include "uart/ProtocolSender.h"
#include "../include/control/ZKDiagram.h"
#include "cstdio"
#include "../include/control/ZKRadioGroup.h"
#include "../include/control/ZKDiagram.h"
#include "../include/control/ZKTextView.h"

#define DIAGRAM_SIZE 100
static MPPOINT sPoints[DIAGRAM_SIZE];

void ZKDiagram::ClearData(int index){
	for (int i = 0; i < DIAGRAM_SIZE; i++) {
			sPoints[i].x = (100 * i) / DIAGRAM_SIZE;
			sPoints[i].y = 500;
		}
	mDiagram1Ptr->setData(index, sPoints, DIAGRAM_SIZE);

}

void ZKDiagram::setLineStraight(int index){
	for (int i = 0; i < DIAGRAM_SIZE; i++) {
				sPoints[i].x = (100 * i) / DIAGRAM_SIZE;
				sPoints[i].y = 5;
			}
		mDiagram1Ptr->setData(index, sPoints, DIAGRAM_SIZE);
}

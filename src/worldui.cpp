#include "worldui.h"

#include "objectui.h"
//#include "subjectui.h"

using namespace std;

void WorldUI::addObject(unique_ptr<Object> obj) {
	objects.push_back(make_unique<ObjectUI>(move(obj)));
}

void WorldUI::addSubject(unique_ptr<Subject> sbj) {
// TODO: Implement SubjectUI class
//	subjects.push_back(make_unique<SubjectUI>(move(sbj)));
}

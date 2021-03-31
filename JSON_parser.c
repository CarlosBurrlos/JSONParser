//JSON Test Parser

/*A JSON object starts with '{', and ends with '}'
 *A JSON obj. field is defined by regex \"\w+\"
 *and is delimited by a ':' character which denotes
 *its value
 *We could also have nested objects
 */


//Struct within which user can define the fields

//Or if it is one of our symbols we need:
//'[', '{', ']', or '}'

#define brkt(c) {(\
	bool ret;\
	if (c == 91 || c == 93 || c == 123 || c == 125)\
									ret = 1;\
	ret;\
								 )}\

#define a_z(c) {(\
	bool ret;\
	if (c >= 65 && c <= 90)\
								 ret = 1;\
	else if (c >= 97 && c <= 122)\
								 ret = 1;\
	else\
								 ret = 0;\
	ret;\
								)}\

#define eat(ptr) {(\
	while ((!a_z(*(ptr)))
					|| !brkt(*(ptr)))\
		ptr++;\
									)}\

char * field_type();
char * field_value();

void * start();
void * pause();
void * stop();
void * scan(char *);
void * consume();

typedef struct obj{
	//
}jsonObj;

typedef struct fsm {
	void * (*state)();
	char * json;
}FSM;

FSM * f;

int parse() {
	FSM * f = malloc(sizeof(FSM));
	f->json = /*Code to GET JSON from API hook*/;
	f->state == start;
	parse_objs:
	while (f->state != stop) {
		if (!json){ f->state = stop; continue;}
		f->state = scan(f->json);
		if (f->state == pause()) {
			//Handle the field assigning
		}
	}
}

//Returns null
void * scan(char * c) {
	if (*c == [)
    f->json++;
  else if (*c == {)
		f->json++;
	else if (*c == '"')
		f->state = pause;
	else if (*c == ':')
		f->state = field_value;
	else if (*c == ' ' || *c == '\n'
					 || *c == '\t')
		f->state = consume;
	else if (*c == ',')
		f->state = field_type;
	else
		f->state = stop;
	return NULL;
}


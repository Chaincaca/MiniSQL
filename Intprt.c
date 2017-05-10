#if 0
Ҫ�󣺸���˵�������û���SQL��䡢�ű�ִ�С��˳����򡣼������·���ָ���ļ��е�interpreter���֡� 
��Ҫ���ж��Ƿ���ڱ������������ȣ�ֻҪ����SQL��ʽ�����Ĵ�����ʾ���ɡ�
�����û����룬������Ӧ�ṹ������ǡ���ĺ��������ü��ɣ�����ʵ�֡���Щ������ûд�꣬���ȼ��������

void CreateIndex(char* in, char* tn, char* an, char force); // ���εĺ����ǣ�index name, table name, attribute name, forceΪ0���� 

void CreateTable(MetaTable T);

void DropIndex(char* in);

void DropTable(char* tn);

void SelectFromWhere(char* tn, Cond cond); // Cond ������ condition 

void DeleteFromWhere(char* tn, Cond cond); 

void InsertIntoValues(char* tn, Values v);


�����漰���Ľṹ��

struct cond{
	char an[MAX_ATTR_NAME]; // ����
	char op;
	// op Լ�����£� 
	// 000 =
	// 001 <=
	// 011 <
	// 100 >
	// 110 >=
	// 111 <>
	struct values* value; // �˽ṹ�е�next���Բ�ʹ�� 
	struct cond* next; // ��һ������������һ��and�ͷ���һ�� 
};

struct values{
	char type; // 00 int, 01 float, 11 char(n)
	char size; // int = float = 4; char = n
	void* data;
	struct values* next;
};

struct attr{
	char pk; // �Ƿ����� 
	char unique; // �Ƿ��һ�޶� 
	char type; // �������� 
	unsigned char size; // ���ݴ�С 
	char name[MAX_ATTR_NAME];
};

struct metaTable{
	char tn[MAX_TABLE_NAME];
	int valid; // һ�����ٸ����� 
	Attr a[MAX_ATTR];
};

typedef struct cond* Cond;
typedef struct values* Values;
typedef struct attr* Attr;
typedef struct metaTable* MetaTable; 

#endif


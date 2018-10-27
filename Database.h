#ifndef DATABASE_H
#define DATABASE_H

const int MAX_ROWS=1000;
const int MAX_ROW_SIZE=20;
const char MAX_KEY_SIZE=50;
const char MAX_VALUE_SIZE=100;

class Database
{
	struct KeyValue {
		char key[MAX_KEY_SIZE];
		char value[MAX_VALUE_SIZE];
		int total;
	} db[MAX_ROWS][MAX_ROW_SIZE];
	int rowCount;
	public:
		Database();
	protected:
		int getRecordForRowNo(int rowId,int noOfKeys, KeyValue kv[]);
		int updateRecordForRowNo(int rowId,int noOfKeys, KeyValue kv[]);
		int insertNewRecord(int noOfKeys, KeyValue kv[]);
};

#endif

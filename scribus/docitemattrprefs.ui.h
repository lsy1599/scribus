/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you want to add, delete, or rename functions or slots, use
** Qt Designer to update this file, preserving your code.
**
** You should not define a constructor or destructor in this file.
** Instead, write your code in functions called init() and destroy().
** These will automatically be called by the form's constructor and
** destructor.
*****************************************************************************/

void DocumentItemAttributes::init()
{
	//blah
}

void DocumentItemAttributes::destroy()
{
	//blah2
}


void DocumentItemAttributes::setup(ObjAttrVector *docItemAttrs)
{
	localAttributes=*docItemAttrs;
	updateTable();
}


ObjAttrVector* DocumentItemAttributes::getNewAttributes()
{
	return &localAttributes;
}


void DocumentItemAttributes::tableItemChanged( int row, int col )
{
	switch (col)
	{
		case 0:
			localAttributes[row].name=attributesTable->text(row, col);
			break;
		case 1:
			localAttributes[row].type=attributesTable->text(row, col);
			break;
		case 2:
			localAttributes[row].value=attributesTable->text(row, col);
			break;
		case 3:
			localAttributes[row].parameter=attributesTable->text(row, col);
			break;
		default:
			break;
		}
}


void DocumentItemAttributes::addEntry()
{
	ObjectAttribute blank;
	localAttributes.append(blank);
	updateTable();
}


void DocumentItemAttributes::updateTable()
{
	attributesTable->setNumRows(localAttributes.count());
	int row=0;
	for(ObjAttrVector::Iterator it = localAttributes.begin(); it!= localAttributes.end(); ++it)
	{
		uint i=0;
		QTableItem *item1 = new QTableItem(attributesTable, QTableItem::WhenCurrent, (*it).name);
		attributesTable->setItem(row, i++, item1);
		QTableItem *item2 = new QTableItem(attributesTable, QTableItem::WhenCurrent, (*it).type);
		attributesTable->setItem(row, i++, item2);
		QTableItem *item3 = new QTableItem(attributesTable, QTableItem::WhenCurrent, (*it).value);
		attributesTable->setItem(row, i++, item3);
		QTableItem *item4 = new QTableItem(attributesTable, QTableItem::WhenCurrent, (*it).parameter);
		attributesTable->setItem(row, i++, item4);
		
		attributesTable->verticalHeader()->setLabel(row, QString("%1").arg(row));
		row++;
	}
	deleteButton->setEnabled(localAttributes.count()!=0);
	copyButton->setEnabled(localAttributes.count()!=0);
	clearButton->setEnabled(localAttributes.count()!=0);
}


void DocumentItemAttributes::deleteEntry()
{
	int currRow=attributesTable->currentRow();
	bool found=false;
	ObjAttrVector::Iterator it;
	int count=0;
	for(it = localAttributes.begin(); it!= localAttributes.end(); ++it)
	{
		if(count==currRow)
		{
			found=true;
			break;
		}
		++count;
	}
	if (found)
	{
		localAttributes.erase(it);
		updateTable();
	}
}


void DocumentItemAttributes::clearEntries()
{
	localAttributes.clear();
	updateTable();
}


void DocumentItemAttributes::copyEntry()
{
	int currRow=attributesTable->currentRow();
	bool found=false;
	ObjAttrVector::Iterator it;
	int count=0;
	for(it = localAttributes.begin(); it!= localAttributes.end(); ++it)
	{
		if(count==currRow)
		{
			found=true;
			break;
		}
		++count;
	}
	if (found)
	{
		localAttributes.append((*it));
		updateTable();
	}
}

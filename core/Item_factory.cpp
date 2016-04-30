#include "item_factory.h"

#include "types.h"
#include "Geodata.h"

BaseItem* ItemFactory::loadFromDb(int type, int session_id) {
	// Создаем верхний элемент
	BaseItem* item = createNew(type, session_id);

	QList<BaseItem*> children = item->loadItemsFromDb();
	
	// Добавляем истинные значения верхнему элементу
	for (int i = 0; i < children.count(); i++)
		
		item->appendChild(children[i]);

	return item;
};

BaseItem* ItemFactory::createNew(int type, int session_id) {
	switch (type)
	{
	
	case ItemTypes::GeodataType:
		return new Geodata(session_id);
	
	default:
		return NULL;
	}
};
#pragma once

#include <DB/Parsers/IAST.h>

namespace DB
{

struct ASTCheckQuery : public IAST
{
	ASTCheckQuery(StringRange range_ = StringRange()) : IAST(range_) {};

	/** Получить текст, который идентифицирует этот элемент. */
	String getID() const override { return ("CheckQuery_" + database + "_" + table); };

	void updateHashWith(SipHash & hash) const override
	{
		hash.update("CheckQuery", strlen("CheckQuery") + 1);
		hash.update(database.data(), database.size() + 1);
		hash.update(table.data(), table.size() + 1);
	}

	ASTPtr clone() const override
	{
		return new ASTCheckQuery(*this);
	}

	std::string database;
	std::string table;
};

}

#include "StreamPosition.h"
#include <algorithm>

StreamPosition::StreamPosition(long line, long column)
{
	SafeSetLine(line);
	SafeSetColumn(column);
}

long StreamPosition::GetLine() const
{
	return m_line;
}

void StreamPosition::SetLine(long value)
{
	SafeSetLine(value);
}

long StreamPosition::GetColumn() const
{
	return m_column;
}

void StreamPosition::SetColumn(long value)
{
	SafeSetColumn(value);
}

void StreamPosition::IncreaseLine(long value)
{
	SafeSetLine(m_line + value);
}

void StreamPosition::IncreaseColumn(long value)
{
	SafeSetColumn(m_column + value);
}

void StreamPosition::DecreaseLine(long value)
{
	SafeSetLine(m_line - value);
}

void StreamPosition::DecreaseColumn(long value)
{
	SafeSetColumn(m_column - value);
}

void StreamPosition::ResetColumn()
{
	m_column = MIN_COLUMN;
}

bool StreamPosition::operator==(const StreamPosition & other) const
{
	return GetLine() == other.GetLine() && GetColumn() == other.GetColumn();
}

bool StreamPosition::operator!=(const StreamPosition & other) const
{
	return GetLine() != other.GetLine() || GetColumn() != other.GetColumn();
}

void StreamPosition::SafeSetLine(long value)
{
	m_line = std::max(MIN_LINE, value);
}

void StreamPosition::SafeSetColumn(long value)
{
	m_column = std::max(MIN_COLUMN, value);
}

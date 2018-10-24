#ifndef INPUTLIBRARY_STREAMPOSITION_H
#define INPUTLIBRARY_STREAMPOSITION_H

class StreamPosition
{
public:
	explicit StreamPosition(long line = MIN_LINE, long column = MIN_COLUMN);
	long GetLine() const;
	void SetLine(long value);
	long GetColumn() const;
	void SetColumn(long value);
	void IncreaseLine(long value = 1);
	void IncreaseColumn(long value = 1);
	void DecreaseLine(long value = 1);
	void DecreaseColumn(long value = 1);
	void ResetColumn();
	bool operator==(StreamPosition const & other) const;
	bool operator!=(StreamPosition const & other) const;

	static long const MIN_LINE;
	static long const MIN_COLUMN;

private:
	long m_line = MIN_LINE;
	long m_column = MIN_COLUMN;

	void SafeSetLine(long value);
	void SafeSetColumn(long value);
};

#endif

#pragma once

namespace GCP
{
	class GCodeCommandVisitor;

	class GCodeCommand
	{
	public:
	protected:
		virtual void Accept(GCodeCommandVisitor& visitor) = 0;

	protected:
		unsigned int m_LineNumber;

		friend class GCodeCommandVisitor;
	};
}

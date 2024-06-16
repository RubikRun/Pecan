#pragma once

#include <chrono>

namespace Pecan {

	namespace TimeUtils
	{

		typedef std::chrono::high_resolution_clock::time_point StdTimePoint;

		/// Enum for different time units
		enum TimeUnit {
			NanoSeconds = 0,
			MicroSeconds = 1,
			MilliSeconds = 2,
			Seconds = 3,
			Minutes = 4,
			Hours = 5,
			Days = 6
		};

		/// Timer class used to keep track of elapsed time since a given moment.
		/// When you create a Timer instance, the timer begins to tick immediately.
		/// At any point you can use the Timer instance to poll the elapsed time since the moment when you created it.
		class Timer
		{
		public:
			/// Creates a Timer instance. Begins timing immediately.
			Timer();

			/// Returns the currently elapsed time since the creation of the timer.
			/// @param timeUnit - Time unit in which the elapsed time will be returned
			/// @return Elapsed time in the given time unit
			float getTime(TimeUnit timeUnit = TimeUnit::Seconds) const;
		private:
			/// Point in time when the Timer instance was created
			StdTimePoint startTime;
		};

	} // namespace TimeUtils

} // namespace Pecan
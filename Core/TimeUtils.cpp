#include "TimeUtils.h"

#include "PecanLogger.h"

namespace Pecan {

	namespace TimeUtils {

		// Function that returns a given duration in some time unit.
		// NOTE: All time units are returned as a single float and they have the precision of the previous smaller time unit.
		//       What this means is that if you want your duration in seconds, you will get it with precision up to milliseconds.
		//       For example you will get 5.143 seconds, and not 5.143859393 seconds.
		//       If you need more precision than 5.143 then you should use milliseconds and you will get 5143.859 milliseconds.
		// @param duration - Duration to be converted, given in nanoseconds
		// @param timeUnit - Time unit to be converted in
		// @return Duration converted in the given time unit
		float getDurationInUnit(const std::chrono::nanoseconds& duration, TimeUnit timeUnit) {
			switch (timeUnit) {
				case NanoSeconds: return float(duration.count());
				case MicroSeconds: return float(duration.count()) / 1000.0f;
				case MilliSeconds: return float(std::chrono::duration_cast<std::chrono::microseconds>(duration).count()) / 1000.0f;
				case Seconds: return float(std::chrono::duration_cast<std::chrono::milliseconds>(duration).count()) / 1000.0f;
				case Minutes: return float(std::chrono::duration_cast<std::chrono::seconds>(duration).count()) / 60.0f;
				case Hours: return float(std::chrono::duration_cast<std::chrono::minutes>(duration).count()) / 60.0f;
				default: PECAN_LOG_ERROR("TimeUtils::getDurationInUnit() not implemented for given TimeUnit"); return 0.0f;
			}
		}

		TimeUtils::Timer::Timer()
			: startTime(std::chrono::high_resolution_clock::now())
		{}

		float Timer::getTime(TimeUnit timeUnit) const {
			const StdTimePoint currentTime = std::chrono::high_resolution_clock::now();
			const long long elapsedMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count();
			return getDurationInUnit(currentTime - startTime, timeUnit);
		}

	} // namespace TimeUtils

} // namespace Pecan
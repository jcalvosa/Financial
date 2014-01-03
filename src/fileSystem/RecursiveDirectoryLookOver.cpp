
#include <boost/filesystem.hpp>
#include <algorithm>

#include "RecursiveDirectoryLookOver.hh"
#include "IPathWorker.hh"

void RecursiveDirectoryLookOver::lookOver(const std::wstring & p, IPathWorker & w)
{
  boost::filesystem::path path(p);

  if (boost::filesystem::exist(path))
  {
    if (boost::filesystem::is_regular_file(path))
    {
      w.workFile(path.string());
    }
    else
    {
      std::for_each(boost::filesystem::recursive_directory_iterator(path),
                    boost::filesystem::recursive_directory_iterator(),
                    [&] (boost::filesystem::directory_entry & entry)
                      {
                        const auto & entryData = entry.path();

                        if (boost::filesystem::is_regular_file(entryData))
                        {
                          w.workFile(entryData.string());
                        }
                        else
                        {
                          w.workPath(entryData.string());
                        }
                      });

    }
  }
}

/**
 * Copyright Soramitsu Co., Ltd. 2017 All Rights Reserved.
 * http://soramitsu.co.jp
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef IROHA_FLAT_FILE_HPP
#define IROHA_FLAT_FILE_HPP

#include <string>
#include <vector>
#include <memory>

namespace iroha {
  namespace ametsuchi {
      class FlatFile {
       public:
        static std::unique_ptr<FlatFile> create(const std::string &path);
        ~FlatFile();
        void add(uint32_t id, const std::vector<uint8_t> &block);
        std::vector<uint8_t> get(uint32_t id) const;
        void remove(uint32_t id);
        std::string directory() const;

       private:
        FlatFile(const std::string &path);
        const std::string dump_dir;
        // Get next auto increment
        // Get last consistent id, check iternal consistency of block store
        uint32_t check_consistency();
        std::string id_to_name(uint32_t id) const;
        uint32_t name_to_id(std::string name) const;
        bool file_exist(const std::string &name) const;
        long file_size(const std::string &filename) const;
      };
  }  // namespace ametsuchi
}  // namespace iroha
#endif  // IROHA_FLAT_FILE_HPP

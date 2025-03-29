# vcpkg-lib-example
vcpkg(パッケージ管理ツール)を用いたC++ライブラリのExample


## 要件
- vcpkg
- cmake v3.30 以上
- Visual Studio 2022 以上


## 使い方
- vcpkg 依存関係設定 : プロジェクトのルートディレクトリに以下のファイルを配置する
  - `vcpkg-configuration.json` : vcpkgレジストリの参照設定ファイル
```json
{
    "default-registry": {
        "kind"       : "git",
        "baseline"   : "300239058e33420acd153135b3f6e6b187828992",
        "repository" : "https://github.com/microsoft/vcpkg"
    },
    "registries": [
        {
            "kind"     : "artifact",
            "location" : "https://github.com/microsoft/vcpkg-ce-catalog/archive/refs/heads/main.zip",
            "name"     : "microsoft"
        },
        {
            "kind"       : "git",
            "repository" : "git@github.com:y0sshi/vcpkg-registry.git",  ## vcpkg-registry リポジトリのURL
            "baseline"   : "...",  ## vcpkg-registry リポジトリのGitコミットハッシュ
            "packages"   : [
                "vcpkg-lib-example"  ## vcpkg-lib-exampleの参照設定
            ]
        }
    ]
}
```
  - `vcpkg.json` : プロジェクトの依存関係設定ファイル
```json
{
    "$schema"        : "https://raw.githubusercontent.com/microsoft/vcpkg/master/scripts/vcpkg.schema.json",
    "name"           : "example",
    "version-string" : "0.1.0",
    "dependencies"   : [
        "vcpkg-lib-example"  ## dependenciesキーに["vcpkg-lib-example"]を指定
    ]
}
```

  - `CMakeLists.txt` : cmake build 設定
```cmake
# ==================================================
# 基本設定 
# ==================================================
cmake_minimum_required(VERSION 3.30)
set(TARGET <TARGET_NAME>)  ## <TARGET_NAME> : ターゲット名を設定
project(${TARGET})
set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ==================================================
# ビルド 
# ==================================================
add_executable(${TARGET}
        <SOURCES>  ## <SOURCES> : ソースコードパスを設定
        )

# ==================================================
# 依存関係設定
# ==================================================
find_package(vcpkg-lib-example CONFIG REQUIRED)
target_link_libraries(${TARGET}
        PRIVATE
            vcpkg-lib-example::vcpkg-lib-example
        )

```


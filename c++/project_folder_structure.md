# Project Directories
PFL prescribes several directories that should appear at the root of the project tree. Not all of the directories are required, but they have an assigned purpose, and no other directory in the filesystem may assume the role of one of these directories. That is, these directories must be the ones used if their purpose is required.

Other directories should not appear at the root.

**NOTE:** *If you have a need not fulfilled by a PFL directory listed below, that is a bug in this specification, and I would love to hear from you! Before reporting, double-check that what you need isn’t listed below and in the following sections.*

## build/
A special directory that should not be considered part of the source of the project. Used for storing ephemeral build results. must not be checked into source control. If using source control, must be ignored using source control ignore-lists.

## src/
Main compilable source location. must be present for projects with compiled components that do not use submodules.

In the presence of include/, also contains private headers.

## include/
Directory for public headers. may be present. may be omitted for projects that do not distinguish between private/public headers. may be omitted for projects that use submodules.

## tests/
Directory for tests.

## examples/
Directory for samples and examples.

## external/
Directory for packages/projects to be used by the project, but not edited as part of the project.

## extras/
Directory containing extra/optional submodules for the project.

## data/
Directory containing non-source code aspects of the project. This might include graphics and markup files.

## tools/
Directory containing development utilities, such as build and refactoring scripts

## docs/
Directory for project documentation.

## libs/
Directory for main project submodules.

[Click here for more details](https://api.csswg.org/bikeshed/?force=1&url=https://raw.githubusercontent.com/vector-of-bool/pitchfork/develop/data/spec.bs)
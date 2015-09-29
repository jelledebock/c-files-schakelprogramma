##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Oefeningenles1
ConfigurationName      :=Debug
WorkspacePath          := "/Users/JelleDeBock/Documents/Schakelprogramma/C_lessons/C"
ProjectPath            := "/Users/JelleDeBock/Documents/Schakelprogramma/C_lessons/C/Oefeningenles1"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Jelle De Bock
Date                   :=24/09/2015
CodeLitePath           :="/Users/JelleDeBock/Library/Application Support/codelite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -dynamiclib -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Oefeningenles1.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/Applications/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/oef1.c$(ObjectSuffix) $(IntermediateDirectory)/oef2.c$(ObjectSuffix) $(IntermediateDirectory)/oef3.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/oef1.c$(ObjectSuffix): oef1.c $(IntermediateDirectory)/oef1.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/JelleDeBock/Documents/Schakelprogramma/C_lessons/C/Oefeningenles1/oef1.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/oef1.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/oef1.c$(DependSuffix): oef1.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/oef1.c$(ObjectSuffix) -MF$(IntermediateDirectory)/oef1.c$(DependSuffix) -MM "oef1.c"

$(IntermediateDirectory)/oef1.c$(PreprocessSuffix): oef1.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/oef1.c$(PreprocessSuffix) "oef1.c"

$(IntermediateDirectory)/oef2.c$(ObjectSuffix): oef2.c $(IntermediateDirectory)/oef2.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/JelleDeBock/Documents/Schakelprogramma/C_lessons/C/Oefeningenles1/oef2.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/oef2.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/oef2.c$(DependSuffix): oef2.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/oef2.c$(ObjectSuffix) -MF$(IntermediateDirectory)/oef2.c$(DependSuffix) -MM "oef2.c"

$(IntermediateDirectory)/oef2.c$(PreprocessSuffix): oef2.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/oef2.c$(PreprocessSuffix) "oef2.c"

$(IntermediateDirectory)/oef3.c$(ObjectSuffix): oef3.c $(IntermediateDirectory)/oef3.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/JelleDeBock/Documents/Schakelprogramma/C_lessons/C/Oefeningenles1/oef3.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/oef3.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/oef3.c$(DependSuffix): oef3.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/oef3.c$(ObjectSuffix) -MF$(IntermediateDirectory)/oef3.c$(DependSuffix) -MM "oef3.c"

$(IntermediateDirectory)/oef3.c$(PreprocessSuffix): oef3.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/oef3.c$(PreprocessSuffix) "oef3.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/



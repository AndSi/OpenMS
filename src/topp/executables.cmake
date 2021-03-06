### the directory name
set(directory source/APPLICATIONS/TOPP)

### list all filenames of the directory here
set(TOPP_executables
AdditiveSeries
BaselineFilter
CompNovo
CompNovoCID
ConsensusID
ConsensusMapNormalizer
DTAExtractor
Decharger
EICExtractor
ExecutePipeline
FalseDiscoveryRate
FeatureFinderMRM
FeatureFinderCentroided
FeatureFinderIdentification
FeatureFinderIsotopeWavelet
FeatureFinderMetabo
FeatureLinkerLabeled
FeatureLinkerUnlabeled
FeatureLinkerUnlabeledQT
FileConverter
FileFilter
FileInfo
FileMerger
GenericWrapper
HighResPrecursorMassCorrector
IDConflictResolver
IDPosteriorErrorProbability
IDFileConverter
IDFilter
IDMapper
IDMerger
IDRipper
IDRTCalibration
ITRAQAnalyzer
IsobaricAnalyzer
InclusionExclusionListCreator
InspectAdapter
InternalCalibration
MapAlignerIdentification
MapAlignerPoseClustering
MapAlignerSpectrum
MapNormalizer
MapRTTransformer
MapStatistics
MascotAdapter
MascotAdapterOnline
MassTraceExtractor
MRMMapper
MyriMatchAdapter
NoiseFilterGaussian
NoiseFilterSGolay
OMSSAAdapter
OpenSwathAnalyzer
OpenSwathChromatogramExtractor
OpenSwathConfidenceScoring
OpenSwathDecoyGenerator
OpenSwathFeatureXMLToTSV
OpenSwathRTNormalizer
PhosphoScoring
PILISIdentification
PILISModelCV
PILISModelTrainer
PILISSpectraGenerator
PTModel
PTPredict
PeakPickerHiRes
PeakPickerWavelet
PepNovoAdapter
PeptideIndexer
PrecursorIonSelector
PrecursorMassCorrector
ProteinInference
ProteinQuantifier
ProteinResolver
RTModel
RTPredict
Resampler
SeedListGenerator
SpecLibSearcher
SpectraFilterWindowMower
SpectraFilterThresholdMower
SpectraFilterSqrtMower
SpectraFilterParentPeakMower
SpectraFilterMarkerMower
SpectraFilterScaler
SpectraFilterBernNorm
SpectraFilterNLargest
SpectraFilterNormalizer
SpectraMerger
TMTAnalyzer
TOFCalibration
TextExporter
MzTabExporter
XTandemAdapter
)

## all targets with need linkage against OpenMS_GUI.lib - they also need to appear in the list above)
set(TOPP_executables_with_GUIlib
ExecutePipeline
Resampler
)

### add filenames to Visual Studio solution tree
set(sources_VS)
foreach(i ${TOPP_executables})
	list(APPEND sources_VS "${i}.cpp")
endforeach(i)
source_group("" FILES ${sources_VS})

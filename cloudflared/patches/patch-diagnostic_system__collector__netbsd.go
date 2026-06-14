$NetBSD$

Prepare SystemCollectorImpl for NetBSD.

--- diagnostic/system_collector_netbsd.go.orig	2026-06-14 01:48:36.000994436 +0000
+++ diagnostic/system_collector_netbsd.go
@@ -0,0 +1,176 @@
+//go:build netbsd
+
+package diagnostic
+
+import (
+	"context"
+	"fmt"
+	"os/exec"
+	"runtime"
+	"strconv"
+	"strings"
+)
+
+type SystemCollectorImpl struct {
+	version string
+}
+
+func NewSystemCollectorImpl(
+	version string,
+) *SystemCollectorImpl {
+	return &SystemCollectorImpl{
+		version,
+	}
+}
+
+func (collector *SystemCollectorImpl) Collect(ctx context.Context) (*SystemInformation, error) {
+	memoryInfo, memoryInfoRaw, memoryInfoErr := collectMemoryInformation(ctx)
+	fdInfo, fdInfoRaw, fdInfoErr := collectFileDescriptorInformation(ctx)
+	disks, disksRaw, diskErr := collectDiskVolumeInformationUnix(ctx)
+	osInfo, osInfoRaw, osInfoErr := collectOSInformationUnix(ctx)
+
+	var memoryMaximum, memoryCurrent, fileDescriptorMaximum, fileDescriptorCurrent uint64
+	var osSystem, name, osVersion, osRelease, architecture string
+
+	err := SystemInformationGeneralError{
+		OperatingSystemInformationError: nil,
+		MemoryInformationError:          nil,
+		FileDescriptorsInformationError: nil,
+		DiskVolumeInformationError:      nil,
+	}
+
+	if memoryInfoErr != nil {
+		err.MemoryInformationError = SystemInformationError{
+			Err:     memoryInfoErr,
+			RawInfo: memoryInfoRaw,
+		}
+	} else {
+		memoryMaximum = memoryInfo.MemoryMaximum
+		memoryCurrent = memoryInfo.MemoryCurrent
+	}
+
+	if fdInfoErr != nil {
+		err.FileDescriptorsInformationError = SystemInformationError{
+			Err:     fdInfoErr,
+			RawInfo: fdInfoRaw,
+		}
+	} else {
+		fileDescriptorMaximum = fdInfo.FileDescriptorMaximum
+		fileDescriptorCurrent = fdInfo.FileDescriptorCurrent
+	}
+
+	if diskErr != nil {
+		err.DiskVolumeInformationError = SystemInformationError{
+			Err:     diskErr,
+			RawInfo: disksRaw,
+		}
+	}
+
+	if osInfoErr != nil {
+		err.OperatingSystemInformationError = SystemInformationError{
+			Err:     osInfoErr,
+			RawInfo: osInfoRaw,
+		}
+	} else {
+		osSystem = osInfo.OsSystem
+		name = osInfo.Name
+		osVersion = osInfo.OsVersion
+		osRelease = osInfo.OsRelease
+		architecture = osInfo.Architecture
+	}
+
+	cloudflaredVersion := collector.version
+	info := NewSystemInformation(
+		memoryMaximum,
+		memoryCurrent,
+		fileDescriptorMaximum,
+		fileDescriptorCurrent,
+		osSystem,
+		name,
+		osVersion,
+		osRelease,
+		architecture,
+		cloudflaredVersion,
+		runtime.Version(),
+		runtime.GOARCH,
+		disks,
+	)
+
+	return info, err
+}
+
+func collectFileDescriptorInformation(ctx context.Context) (
+	*FileDescriptorInformation,
+	string,
+	error,
+) {
+	const (
+		fileDescriptorLine = 0
+		currentFilesField  = 0
+		maxFilesField      = 1
+	)
+	command := exec.CommandContext(ctx, "pstat", "-T")
+
+	stdout, err := command.Output()
+	if err != nil {
+		return nil, "", fmt.Errorf("error retrieving output from command '%s': %w", command.String(), err)
+	}
+
+	output := string(stdout)
+
+	lines := strings.Split(output, "\n")
+	line := strings.TrimSuffix(lines[fileDescriptorLine], " files")
+	fields := strings.Split(line, "/")
+	fileDescriptorCurrent, err := strconv.ParseUint(fields[0], 10, 64)
+	if err != nil {
+		return nil, "", fmt.Errorf(
+			"error parsing files current field '%s': %w",
+			fields[0],
+			err,
+		)
+	}
+	fileDescriptorMaximum, err := strconv.ParseUint(fields[1], 10, 64)
+	if err != nil {
+		return nil, "", fmt.Errorf("error parsing files max field '%s': %w", fields[1], err)
+	}
+	fileDescriptorInfo := &FileDescriptorInformation{fileDescriptorMaximum, fileDescriptorCurrent}
+
+	// returning raw output in case other collected information
+	// resulted in errors
+	return fileDescriptorInfo, output, nil
+}
+
+func collectMemoryInformation(ctx context.Context) (
+	*MemoryInformation,
+	string,
+	error,
+) {
+	const (
+		memTotalPrefix     = "MemTotal"
+		memAvailablePrefix = "MemFree"
+	)
+
+	command := exec.CommandContext(ctx, "cat", "/proc/meminfo")
+
+	stdout, err := command.Output()
+	if err != nil {
+		return nil, "", fmt.Errorf("error retrieving output from command '%s': %w", command.String(), err)
+	}
+
+	output := string(stdout)
+
+	mapper := func(field string) (uint64, error) {
+		field = strings.TrimRight(field, " kB")
+
+		return strconv.ParseUint(field, 10, 64)
+	}
+
+	memoryInfo, err := ParseMemoryInformationFromKV(output, memTotalPrefix, memAvailablePrefix, mapper)
+	if err != nil {
+		return nil, output, err
+	}
+
+	// returning raw output in case other collected information
+	// resulted in errors
+	return memoryInfo, output, nil
+}

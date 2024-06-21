# $NetBSD$
#
# Based on https://git.pleroma.social/pleroma/pleroma/-/blob/develop/Dockerfile?ref_type=heads#L13

.PHONY: all clean config deps release

RM?=rm
LN?=ln
SED?=sed
PAX?=pax
FIND?=find
ECHO?=echo
TOUCH?=touch
MKDIR?=mkdir
INSTALL?=install
INSTALL_DIR?=$(INSTALL) -m755 -d
INSTALL_DATA?=$(INSTALL) -m644
INSTALL_PROGRAM?=$(INSTALL) -m755
#ERTS_VERSION=erts-$(shell erl -eval 'io:format(erlang:system_info(version)), halt().' -noshell)

all: release
deps: | deps/.deps-done
config: | config/.config-done
release: | release/.release-done

clean:
	$(RM) -rf deps
	$(RM) -rf release
	$(RM) -rf config/prod.secret.exs
	$(RM) -rf $(TARGET_PREFIX)/*

config/.config-done:
	$(MKDIR) -p config
	$(ECHO) "import Config" > config/prod.secret.exs
	$(TOUCH) $@

deps/.deps-done: | config/.config-done
	$(MIX) local.hex --force
	$(MIX) deps.get --only prod
	$(TOUCH) $@

release/.release-done: | deps/.deps-done
	$(MKDIR) -p release
	$(MIX) release --path release

	$(FIND) release/bin/pleroma* -type f -exec $(SED) -i "1s|.*|\#!$(PLEROMA_SHELL)|" {} ";"
	$(FIND) release/releases/$(PLEROMA_VERSION) -type f \( -name elixir -or -name env.sh -or -name iex \) \
		-exec $(SED) -i "1s|.*|\#!$(PLEROMA_SHELL)|" {} ";"

	$(TOUCH) $@

install: release/.release-done
	$(INSTALL_DIR) $(PLEROMA_PREFIX)
	$(INSTALL_DATA) release/OTP_VERSION	$(PLEROMA_PREFIX)

	$(INSTALL_DIR) release/bin $(TARGET_PREFIX)/bin
	$(INSTALL_PROGRAM) $(wildcard release/bin/*) $(TARGET_PREFIX)/bin

	$(INSTALL_DIR) $(PLEROMA_PREFIX)/lib
	$(PAX) -rw -pp -s ':^release/lib::' release/lib $(PLEROMA_PREFIX)/lib

	$(MKDIR) -p $(PLEROMA_PREFIX)/releases
	$(PAX) -rw -pp -s ':^release/releases::' release/releases $(PLEROMA_PREFIX)/releases

	$(INSTALL_DIR) $(TARGET_PREFIX)/etc/pleroma
	$(INSTALL_DIR) $(TARGET_PREFIX)/var/pleroma
	$(INSTALL_DIR) $(TARGET_PREFIX)/share/examples/pleroma

# only install if nginx option is enabled
#	$(INSTALL_DATA) installation/pleroma.nginx $(TARGET_PREFIX)/share/examples
	$(INSTALL_DATA) installation/netbsd/rc.d/pleroma $(TARGET_PREFIX)/share/examples/pleroma/pleroma.rc

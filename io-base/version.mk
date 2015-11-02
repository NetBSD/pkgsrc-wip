# $NetBSD: version.mk,v 1.4 2009/07/04 19:17:23 milosn Exp $

IO_VERSION=		2013.12.04
DISTNAME=		io-${IO_VERSION}
MASTER_SITES=		${MASTER_SITE_GITHUB:=stevedekorte/}
GITHUB_PROJECT=		io
EXTRACT_USING=		bsdtar

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pax pkg-config
MAKE_JOBS_SAFE=		no

DISTINFO_FILE=		${.CURDIR}/../../wip/io-vm/distinfo

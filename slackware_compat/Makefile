# $NetBSD: Makefile,v 1.4 2006/05/19 16:51:37 ykomatsu Exp $
#

DISTNAME=		slackware_compat-9.1.2
CATEGORIES=		emulators
MASTER_SITES=		# none
DISTFILES=		# none

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://slackware.com/
COMMENT=		Slackware emulation base

DEPENDS+=		slackware_aaa_base>=9.1.0:../../wip/slackware_aaa_base
DEPENDS+=		slackware_aaa_elflibs>=9.1.0:../../wip/slackware_aaa_elflibs
DEPENDS+=		slackware_coreutils>=2.3.2:../../wip/slackware_coreutils
DEPENDS+=		slackware_bash>=2.05b:../../wip/slackware_bash

EXTRACT_ONLY=		# empty
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes
NO_MTREE=		yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"

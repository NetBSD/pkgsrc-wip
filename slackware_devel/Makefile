# $NetBSD: Makefile,v 1.5 2004/03/12 16:23:45 mpasternak Exp $
#

DISTNAME=		slackware_devel-9.1.2
CATEGORIES=		emulators
MASTER_SITES=		# none
DISTFILES=		# none

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://slackware.com/
COMMENT=		Meta package for slackware_compat development

DEPENDS+=		slackware_gcc>=3.3.3:../../wip/slackware_gcc
DEPENDS+=		slackware_glibc>=2.3.2:../../wip/slackware_glibc
DEPENDS+=		slackware_make>=3.80:../../wip/slackware_make
DEPENDS+=		slackware_sed>=4.0.9:../../wip/slackware_sed
DEPENDS+=		slackware_awk>=3.1.3:../../wip/slackware_awk
DEPENDS+=		slackware_grep>=2.5:../../wip/slackware_grep
DEPENDS+=		slackware_binutils>=2.14.90.0.8:../../wip/slackware_binutils

EXTRACT_ONLY=		# empty
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes
NO_BUILDLINK=		yes
NO_MTREE=		yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"

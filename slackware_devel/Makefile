# $NetBSD: Makefile,v 1.1.1.1 2004/03/12 15:13:42 mpasternak Exp $
#

DISTNAME=		slackware_devel-9.1.2
CATEGORIES=		emulators
MASTER_SITES=		# none
DISTFILES=		# none

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://slackware.com/
COMMENT=		Meta package for slackware_compat development

DEPENDS+=		slackware_gcc>=3.3.3:../../wip/slackware_gcc
DEPENDS+=		slackware_glibc>=2.3.2:../../wip/slackware-glibc

EXTRACT_ONLY=		# empty
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes
NO_BUILDLINK=		yes
NO_MTREE=		yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"

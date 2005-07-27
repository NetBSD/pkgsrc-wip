# $NetBSD: Makefile,v 1.10 2005/07/27 16:30:13 thomasklausner Exp $
#

DISTNAME=		slackware_devel-9.1.2
CATEGORIES=		emulators
MASTER_SITES=		# none
DISTFILES=		# none

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://slackware.com/
COMMENT=		Meta package for slackware_compat development

DEPENDS+=		slackware_gcc>=3.3.3:../../wip/slackware_gcc
DEPENDS+=		slackware_bc>=1.06:../../wip/slackware_bc
DEPENDS+=		slackware_findutils>=4.1.7:../../wip/slackware_findutils
DEPENDS+=		slackware_gzip>=1.3.3:../../wip/slackware_gzip
DEPENDS+=		slackware_tar>=1.3.25:../../wip/slackware_tar
DEPENDS+=		slackware_glibc>=2.3.2:../../wip/slackware_glibc
DEPENDS+=		slackware_make>=3.80:../../wip/slackware_make
DEPENDS+=		slackware_sed>=4.0.9:../../wip/slackware_sed
DEPENDS+=		slackware_awk>=3.1.3:../../wip/slackware_awk
DEPENDS+=		slackware_grep>=2.5:../../wip/slackware_grep
DEPENDS+=		slackware_ncurses>=5.4:../../wip/slackware_ncurses
DEPENDS+=		slackware_kernel_headers>=2.4.25:../../wip/slackware_kernel_headers
DEPENDS+=		slackware_binutils>=2.14.90.0.8:../../wip/slackware_binutils

EXTRACT_ONLY=		# empty
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes
NO_MTREE=		yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"

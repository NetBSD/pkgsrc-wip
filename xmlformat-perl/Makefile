# $NetBSD: Makefile,v 1.7 2008/07/15 17:07:14 bubuchka Exp $
#

DISTNAME=		xmlformat-${XMLFORMAT_VERSION}
PKGNAME=		xmlformat-perl-${XMLFORMAT_VERSION}
CATEGORIES=		textproc
MASTER_SITES=		http://www.kitebird.com/software/xmlformat/

MAINTAINER=		mishka@NetBSD.org
HOMEPAGE=		http://www.kitebird.com/software/xmlformat/
COMMENT=		Configurable XML formatter, Perl version

CONFLICTS+=		xmlformat-ruby-[0-9]*

USE_TOOLS+=		perl:run
REPLACE_PERL=		xmlformat.pl

NO_BUILD=		yes
PKG_INSTALLATION_TYPES=	overwrite pkgviews

DISTINFO_FILE=		${.CURDIR}/../../wip/xmlformat-docs/distinfo
DESCR_SRC=		${.CURDIR}/../../wip/xmlformat-docs/DESCR.common \
			${PKGDIR}/DESCR

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xmlformat.pl ${PREFIX}/bin/xmlformat

.include "../../wip/xmlformat-docs/version.mk"
.include "../../mk/bsd.pkg.mk"

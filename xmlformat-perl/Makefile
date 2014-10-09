# $NetBSD: Makefile,v 1.9 2014/10/09 14:06:32 thomasklausner Exp $
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

DISTINFO_FILE=		${.CURDIR}/../../wip/xmlformat-docs/distinfo
DESCR_SRC=		${.CURDIR}/../../wip/xmlformat-docs/DESCR.common \
			${PKGDIR}/DESCR

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xmlformat.pl ${DESTDIR}${PREFIX}/bin/xmlformat

.include "../../wip/xmlformat-docs/version.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1.1.1 2005/04/20 14:47:30 bubuchka Exp $
#

DISTNAME=		xmlformat-1.03
PKGNAME=		xmlformat-perl-1.03
CATEGORIES=		textproc wip
MASTER_SITES=		http://www.kitebird.com/software/xmlformat/

MAINTAINER=		mishka@apk.od.ua
HOMEPAGE=		http://www.kitebird.com/software/xmlformat/
COMMENT=		Configurable XML formatter, Perl version

USE_PERL5=		run
REPLACE_PERL=		xmlformat.pl

NO_BUILD=		yes
PKG_INSTALLATION_TYPES=	overwrite pkgviews

DISTINFO_FILE=		${.CURDIR}/../../wip/xmlformat-docs/distinfo
DESCR_SRC=		${.CURDIR}/../../wip/xmlformat-docs/DESCR.common \
			${PKGDIR}/DESCR

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xmlformat.pl ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"

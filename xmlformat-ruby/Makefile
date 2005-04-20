# $NetBSD: Makefile,v 1.2 2005/04/20 15:08:46 bubuchka Exp $
#

DISTNAME=		xmlformat-${XMLFORMAT_VERSION}
PKGNAME=		xmlformat-ruby-${XMLFORMAT_VERSION}
CATEGORIES=		textproc wip
MASTER_SITES=		http://www.kitebird.com/software/xmlformat/

MAINTAINER=		mishka@apk.od.ua
HOMEPAGE=		http://www.kitebird.com/software/xmlformat/
COMMENT=		Configurable XML formatter, Ruby version

REPLACE_RUBY=		xmlformat.rb

NO_BUILD=		yes
PKG_INSTALLATION_TYPES=	overwrite pkgviews

DISTINFO_FILE=		${.CURDIR}/../../wip/xmlformat-docs/distinfo
DESCR_SRC=		${.CURDIR}/../../wip/xmlformat-docs/DESCR.common \
			${PKGDIR}/DESCR

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xmlformat.rb ${PREFIX}/bin

.include "../../wip/xmlformat-docs/version.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../lang/ruby/replace.mk"
.include "../../mk/bsd.pkg.mk"

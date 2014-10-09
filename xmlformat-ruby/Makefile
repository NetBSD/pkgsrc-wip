# $NetBSD: Makefile,v 1.8 2014/10/09 14:06:32 thomasklausner Exp $
#

DISTNAME=		xmlformat-${XMLFORMAT_VERSION}
PKGNAME=		xmlformat-ruby-${XMLFORMAT_VERSION}
CATEGORIES=		textproc
MASTER_SITES=		http://www.kitebird.com/software/xmlformat/

MAINTAINER=		mishka@NetBSD.org
HOMEPAGE=		http://www.kitebird.com/software/xmlformat/
COMMENT=		Configurable XML formatter, Ruby version

CONFLICTS+=		xmlformat-perl-[0-9]*

REPLACE_RUBY=		xmlformat.rb

NO_BUILD=		yes

DISTINFO_FILE=		${.CURDIR}/../../wip/xmlformat-docs/distinfo
DESCR_SRC=		${.CURDIR}/../../wip/xmlformat-docs/DESCR.common \
			${PKGDIR}/DESCR

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xmlformat.rb ${DESTDIR}${PREFIX}/bin/xmlformat

.include "../../wip/xmlformat-docs/version.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../lang/ruby/replace.mk"
.include "../../mk/bsd.pkg.mk"

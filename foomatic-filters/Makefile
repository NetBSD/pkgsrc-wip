# $NetBSD: Makefile,v 1.3 2004/02/02 14:26:11 bjan2 Exp $

DISTNAME=	foomatic-filters-3.0-20031224
CATEGORIES=	print
MASTER_SITES=	http://www.linuxprinting.org/download/foomatic/

MAINTAINER=	pkgsrc@bjan.net
HOMEPAGE=	http://www.linuxprinting.org/
COMMENT=	Spooler independent postscript printing filter

GNU_CONFIGURE=		YES
CONFIG_GUESS_OVERRIDE=  ${WRKSRC}/config.guess
CONFIG_SUB_OVERRIDE=    ${WRKSRC}/config.sub

USE_GNU_TOOLS+=	make
USE_PERL5=	yes
PERL5_REQD=	5.6
INSTALL_TARGET=	install-bin install-man

PKG_SYSCONFSUBDIR=	foomatic
EGDIR=			${PREFIX}/share/examples/foomatic-filters/
CONF_FILES=		${EGDIR}/filter.conf ${PKG_SYSCONFDIR}/filter.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/filter.conf ${EGDIR}

.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.5 2004/01/25 02:34:01 grantbeattie Exp $
#

DISTNAME=	XML-XSH-1.6
PKGNAME=	${DISTNAME:S/XML-XSH/xsh/}
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xsh/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://xsh.sourceforge.net/
COMMENT=	XML Editing Shell

DEPENDS+=	p5-Parse-RecDescent>=1.94:../../devel/p5-Parse-RecDescent
DEPENDS+=	p5-Term-ReadLine>=1.12:../../devel/p5-Term-ReadLine
DEPENDS+=	p5-XML-LibXML>=1.31:../../textproc/p5-XML-LibXML

USE_PERL5=	yes
USE_GNU_TOOLS+=	make
USE_BUILDLINK2=	yes
PKG_SHELL=	${PREFIX}/bin/xsh

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

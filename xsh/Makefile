# $NetBSD: Makefile,v 1.3 2003/07/04 13:09:15 jmmv Exp $
#

DISTNAME=	XML-XSH-1.6
PKGNAME=	${DISTNAME:S/XML-XSH/xsh/}
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xsh/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://xsh.sourceforge.net/
COMMENT=	XML Editing Shell

DEPENDS+=	p5-Parse-RedDescent>=1.94:../../devel/p5-Parse-RedDescent
DEPENDS+=	p5-Term-ReadLine>=1.12:../../devel/p5-Term-ReadLine
DEPENDS+=	p5-XML-LibXML>=1.31:../../textproc/p5-XML-LibXML

USE_PERL5=	yes
USE_GMAKE=	yes
USE_BUILDLINK2=	yes
PKG_SHELL=	${PREFIX}/bin/xsh

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1.1.1 2003/10/07 18:07:46 xtraeme Exp $
#

DISTNAME=	Glib-${VERSION}
PKGNAME=	p5-Glib2-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk2-perl/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
COMMENT=	Perl bindings for Glib 2

USE_BUILDLINK2=	yes

PERL5_REQD=	5.8
VERSION=	1.00rc4

DEPENDS+=	p5-ExtUtils-Depends-[0-9]*:../../wip/p5-ExtUtils-Depends
DEPENDS+=	p5-ExtUtils-PkgConfig-[0-9]*:../../wip/p5-ExtUtils-PkgConfig

.include "../../devel/glib2/buildlink2.mk"
.include "../../lang/perl5/module.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1.1.1 2005/03/01 12:44:17 peterih Exp $
#

DISTNAME=		gromacs-3.2.1
CATEGORIES=		wip
MASTER_SITES=		ftp://ftp.gromacs.org/pub/gromacs/

MAINTAINER=		pih@bsdmail.dk
HOMEPAGE=		ftp://ftp.gromacs.org/pub/gromacs/
COMMENT=		Molecular dynamics package

DEPENDS+=               fftw2>=2.1.5:../../math/fftw2
DEPENDS+=               binutils>=2.10.91:../../devel/binutils

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--without-fftw

.include "../../math/fftw2/buildlink3.mk"
.include "../../x11/lesstif/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

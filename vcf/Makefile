# $NetBSD: Makefile,v 1.1.1.2 2009/02/10 08:17:58 othyro Exp $
#

DISTNAME=	vcf-0.0.5
CATEGORIES=	audio
MASTER_SITES=	http://www.suse.de/~mana/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.suse.de/~mana/
COMMENT=	Some LADSPA plugins for audio EQ biquad filters

do-install:
	${INSTALL_LIB_DIR} ${BUILDLINK_PREFIX.ladspa}/lib/ladspa
	${INSTALL_LIB} ${WRKSRC}/vcf.so ${BUILDLINK_PREFIX.ladspa}/lib/ladspa

.include "../../audio/ladspa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

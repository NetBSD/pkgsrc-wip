# $NetBSD$

DISTNAME=	GDSreader-0.4.2
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=makoto-fujiwara/}

MAINTAINER=	makoto@ki.nu
HOMEPAGE=	https://github.com/makoto-fujiwara/
COMMENT=	Calma Stream Format (GDSII) reader
LICENSE=	gnu-gpl-v2

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGBASE}

AUTO_MKDIRS=	yes
INSTALLATION_DIRS=	bin ${EXAMPLESDIR}

do-install:
	for i in gdsreader maptolayer; do \
	${INSTALL_PROGRAM} ${WRKSRC}/$$i ${DESTDIR}${PREFIX}/bin ;\
	done

post-install:
	for i in			\
		README			\
		README.povray		\
		layers.config		\
		layers.config.5AM.4ML	\
		layers.config.7HP.5ML	\
		test.gds		\
		; do			\
	${INSTALL_DATA} ${WRKSRC}/$$i ${DESTDIR}${EXAMPLESDIR} ;\
	done
	for i in			\
		gdsreader.1		\
		maptolayer.1		\
		; do			\
	${INSTALL_DATA} ${WRKSRC}/$$i ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1;\
	done

.include "../../mk/bsd.pkg.mk"

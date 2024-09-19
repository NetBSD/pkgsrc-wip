# $NetBSD$

DISTNAME=	smbnetfs-0.6.3
PKGNAME=	fuse-${DISTNAME}
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=smbnetfs/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/smbnetfs
COMMENT=	Mount a Samba/Microsoft share as a regular Unix filesystem
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config

GNU_CONFIGURE=	yes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing config file paths.
SUBST_FILES.paths=	*.FAQ
SUBST_FILES.paths+=	doc/*.FAQ
SUBST_FILES.paths+=	doc/INSTALL
SUBST_FILES.paths+=	src/reconfigure.c
SUBST_FILES.paths+=	debian/smbnetfs.1
SUBST_SED.paths=	-e 's,/etc,${PKG_SYSCONFDIR},g'

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/examples/smbnetfs

.include "../../mk/bsd.prefs.mk"

# XXX: hack should probably be moved to fuse.buildlink3.mk
pre-configure:
.if ${OPSYS} == "NetBSD"
	${MKDIR} ${BUILDLINK_DIR}/include/fuse
	${CP} /usr/include/fuse*.h ${BUILDLINK_DIR}/include/fuse
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/debian/smbnetfs.1 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${MV} ${DESTDIR}${PREFIX}/share/doc/${PKGNAME_NOREV:S/fuse-//g}/smbnetfs.conf \
	    ${DESTDIR}${PREFIX}/share/examples/smbnetfs/smbnetfs.conf

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/samba4/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

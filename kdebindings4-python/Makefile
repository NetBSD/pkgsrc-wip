# $NetBSD: Makefile,v 1.6 2009/07/10 22:15:23 absd Exp $

PKGNAME=	kdebindings4-python-${_KDE_VERSION}
DISTNAME=	kdebindings-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	Python bindings for the KDE integrated X11 desktop

.include "../../wip/kde4/Makefile.kde4"

PKG_DESTDIR_SUPPORT=	user-destdir

# BUILD_MAKE_FLAGS+= VERBOSE=1

CMAKE_ARGS+=	-DENABLE_SMOKE=off
CMAKE_ARGS+=	-DENABLE_QYOTO=off
CMAKE_ARGS+=	-DENABLE_QTRUBY=off -DENABLE_KORUNDUM=off
CMAKE_ARGS+=	-DENABLE_KROSSRUBY=off
CMAKE_ARGS+=	-DENABLE_KROSSJAVA=off -DENABLE_KROSSFALCON=off
CMAKE_ARGS+=	-DPYTHON_EXECUTABLE:FILEPATH=${PYTHONBIN}

PYTHON_VERSIONS_ACCEPTED=	26 25
PY_PATCHPLIST=			yes
PLIST_SUBST+=			PYVERSSUFFIX=${PYVERSSUFFIX:Q}

post-install:
	${RM} ${DESTDIR}${PREFIX}/share/sip2.5/PyKDE4/akonadi/messagethreadingattribute.sip.orig
	${RM} ${DESTDIR}${PREFIX}/share/sip2.5/PyKDE4/dnssd/servicebase.sip.orig
	${RM} ${DESTDIR}${PREFIX}/share/sip2.5/PyKDE4/kdecore/kptydevice.sip.orig
	${RM} ${DESTDIR}${PREFIX}/share/sip2.5/PyKDE4/kdecore/typedefs.sip.orig
	${RM} ${DESTDIR}${PREFIX}/share/sip2.5/PyKDE4/kio/global.sip.orig
	${RM} ${DESTDIR}${PREFIX}/share/sip2.5/PyKDE4/kio/kacl.sip.orig
	${RM} ${DESTDIR}${PREFIX}/share/sip2.5/PyKDE4/kparts/factory.sip.orig
	${RM} ${DESTDIR}${PREFIX}/share/sip2.5/PyKDE4/phonon/backendcapabilities.sip.orig
	${RM} ${DESTDIR}${PREFIX}/share/sip2.5/PyKDE4/plasma/abstractrunner.sip.orig

.include "../../wip/kde4/kde4.mk"

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kdepimlibs4/buildlink3.mk"
BUILDLINK_API_DEPENDS.py-sip+=  ${PYPKGPREFIX}-sip>=4.7.9
.include "../../x11/py-sip/buildlink3.mk"
.include "../../x11/py-qt4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

#pragma once

#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreLogManager.h>
#include <OgreRoot.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreConfigFile.h>
#include <OgreWindowEventUtilities.h>
#include <OgreRenderTargetListener.h> 

#include <OISMouse.h>
#include <OISKeyboard.h>
#include <OISInputManager.h>

#include <SdkCameraMan.h>

#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/Ogre/Renderer.h>

#include <unordered_map>
#include <list>
#include <string>
#include <cstring>
#include <cstdlib>

#include "Perlin.h"
#include "NetManager.h"
#include "GameManager.h"
#include "OISManager.h"
#include "Simulator.h"
#include "Cube.h"

class Application : public Ogre::FrameListener, public Ogre::WindowEventListener, public Ogre::RenderTargetListener
{
public:
	Application();
	virtual ~Application();

	virtual void init();

	Ogre::Root * mRoot;
	Ogre::String mResourcesCfg;
	Ogre::String mPluginsCfg;
	Ogre::RenderWindow * mRenderWindow;
	Ogre::SceneManager * mSceneManager;
	OgreBites::SdkCameraMan * cameraMan;
	Ogre::Timer* t1;
	Ogre::Camera* playerCam;

	NetManager* netManager = nullptr;

	GameManager* gameManager;
	OISManager* _oisManager;
	Simulator* _simulator;

    CEGUI::OgreRenderer* mRenderer;
	
	std::vector<Ogre::Camera*> cameras;

	Ogre::StaticGeometry* sg;
	Ogre::Entity* grassCube = nullptr;

	Perlin* perlin;

	int points;
	int width;
	int height;

	double fps = 300.0;

	bool begin = false;
	bool mRunning = true;

	virtual bool frameRenderingQueued(const Ogre::FrameEvent &evt) override;
	void createRootEntity(std::string name, std::string mesh, int x, int y, int z);
	Ogre::Entity* createRootEntity(std::string mesh, int x, int y, int z);
	void createChildEntity(std::string name, std::string mesh, Ogre::SceneNode* sceneNode, int x, int y, int z);
	Cube* createCube(Ogre::String nme, GameObject::objectType tp, Ogre::String meshName, int x, int y, int z, Ogre::Vector3 scale, Ogre::Degree pitch, Ogre::Degree yaw, Ogre::Degree roll, Ogre::SceneManager* scnMgr, GameManager* ssm, Ogre::Real mss, Ogre::Real rest, Ogre::Real frict, bool kinematic, Simulator* mySim);
	bool update(const Ogre::FrameEvent &evt);
	bool handleGUI(const Ogre::FrameEvent &evt);
	bool updateServer(const Ogre::FrameEvent &evt);
	bool updateClient(const Ogre::FrameEvent &evt);

	void setupWindowRendererSystem(void);
	void setupResources(void);
	void setupOIS(void);
	void setupCEGUI(void);
	void setupCameras(void);
	void setupGM(void);
	void setupLighting(void);
	void createObjects(void);
	void testPerlinGeneration();
	bool Quit(const CEGUI::EventArgs &e);

	bool setupNetwork(bool);
	bool error();
	std::unordered_map<std::string, char*> dataParser(char*);
	void hideGui();
	void showGui();
	void resetNetManager();
};

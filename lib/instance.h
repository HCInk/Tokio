#ifndef DIS_LIGHT_INSTANCE_H
#define DIS_LIGHT_INSTANCE_H

#include <iostream>
#include <string>
#include <napi.h>
#include <vector>
#include "socket/http/DisHttpClient.h"
#include "socket/dis_websocket.h"
#include "socket/dis_voice_websocket.h"
class Instance {
 public:
  Instance(std::string& token);
  Napi::Object generateBindings(Napi::Env env);
  void generateVoiceBindings(Napi::Env env, Napi::Function callback, std::string& server_id, std::string& channel_id, DisWebsocket* sock);
  int bootstrap();
  bool hold = true;
  DisWebsocket* socket = nullptr;
  DisHttpClient* httpClient = nullptr;
  std::vector<DisVoiceWebsocket*> voice_connections;
 private:
  std::string token;



};
#endif //DIS_LIGHT_INSTANCE_H
